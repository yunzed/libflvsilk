#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "AS3/AS3.h"
#include "silkencoder.h"
#include "SKP_Silk_SDK_API.h"

int 	m_sampleRate;
int	m_channels = 2;
int	m_quality = 8;
int	m_inputFrameSize = 0;
void*   m_pSilkEnc = NULL;
SKP_SILK_SDK_EncControlStruct m_encControl;

#define FRAME_LENGTH_MS         20
static int silkbps[] = {5000,  8000, 12000, 14000, 16000, 18000, 20000, 22000, 24000, 40000, 100000	};

int 	silk_encoder_start(int sampleRate, int channels, int quality)
{
	int ret;
	int encSize = 0;	
	
	m_sampleRate = sampleRate;
	m_channels = channels;	
	m_quality = quality;
	if( m_quality < 0 || m_quality >= 10 ) 
		m_quality = 8;
	m_inputFrameSize = m_sampleRate* FRAME_LENGTH_MS  / 1000 * 16/8;
	
	m_encControl.API_sampleRate = m_sampleRate;

	ret = SKP_Silk_SDK_Get_Encoder_Size( &encSize );
	if( ret ) {
		return -1;
	}

	m_pSilkEnc = (void*)malloc( encSize );
	if(m_pSilkEnc == NULL){
		return -1;
	}

	ret = SKP_Silk_SDK_InitEncoder( m_pSilkEnc, &m_encControl );
	if( ret ) {
		return -1;
	}
		/* Set Encoder parameters */
	m_encControl.API_sampleRate       = m_sampleRate;
	m_encControl.maxInternalSampleRate  = 24000;
	m_encControl.packetSize           = m_sampleRate * FRAME_LENGTH_MS/1000;
	m_encControl.packetLossPercentage = 3;
	m_encControl.useInBandFEC         = 0;
	m_encControl.useDTX               = 1;
	m_encControl.complexity           = 0;
	m_encControl.bitRate              = silkbps[m_quality];
	
	return 0;
}

int silk_encoder_encode(unsigned char* in, short inlen, unsigned char* out, short out_len)
{
	if( in == 0 || m_pSilkEnc == NULL ){
		return 0;
	}

	const unsigned char* cur =  in;
	const unsigned char* end =  cur + inlen;    	
	unsigned char* out_temp = out;
	int 	nFrameLen = 0;
	short out_len_temp = 0;
	short ret = 0;
	short a = 0;
	while(cur < end)
	{
		out_len_temp = out_len;
		nFrameLen = m_inputFrameSize;
		SKP_Silk_SDK_Encode( m_pSilkEnc, &m_encControl, (short*)(cur), nFrameLen/2, (SKP_uint8 *)(out_temp+2), &out_len_temp );
		a = ((0xFC<<8) | out_len_temp);
		out_temp[0] = a&0xFF;
		out_temp[1] = (a&0xFF00)>>8;
		
		cur  += nFrameLen;
		inlen  -= nFrameLen;
		out_temp += (out_len_temp + 2);
		ret += (out_len_temp + 2);
	}

	return  ret;
}

void silk_encoder_stop()
{
	if(m_pSilkEnc){
		free( m_pSilkEnc);
		m_pSilkEnc = NULL;
	}
}
