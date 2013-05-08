#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "AS3/AS3.h"
#include "silkdecoder.h"
#include "SKP_Silk_SDK_API.h"

int m_sampleRate;
void*   m_pSilkDec = NULL;
SKP_SILK_SDK_DecControlStruct m_DecControl;

inline int FrameLength(const unsigned char* audio, int len) {
	if(len < 2)
		return -1;

	short header = (*(short*)audio);
	if((header&0xfc00) != 0xfc00)
		return 0;

	return (header & 0x3ff);
}

int 	silk_decoder_start(int sampleRate)
{
	int ret;
	int decSizeBytes = 0;	
	m_sampleRate = sampleRate;
	
	m_DecControl.API_sampleRate = m_sampleRate;

	ret = SKP_Silk_SDK_Get_Decoder_Size( &decSizeBytes );
	if( ret ) {
		return -1;
	}

	m_pSilkDec = (void*)malloc( decSizeBytes );
	if(m_pSilkDec == NULL){
		return -1;
	}

	ret = SKP_Silk_SDK_InitDecoder( m_pSilkDec );
	if( ret ) {
		return -1;
	}
	
	return 0;
}

int silk_decoder_decode(unsigned char* in, short inlen, unsigned char* out, short out_len)
{
	if(in == 0 ){
		return 0;
	}

	const unsigned char* cur =  in;
	const unsigned char* end =  cur + inlen;    	
	unsigned char* out_temp = out;
	int 	nFrameLen = 0;
	short out_len_temp = 0;
	short ret = 0;
	while(cur < end)
	{
		nFrameLen = FrameLength(cur, inlen);
		SKP_Silk_SDK_Decode( m_pSilkDec, &m_DecControl, 0,(SKP_uint8 *)(cur + 2), nFrameLen, (short*)out_temp, &out_len_temp );

		cur  += (2 + nFrameLen);
		inlen  -= (2 + nFrameLen);
		out_temp += out_len_temp*2;
		ret += out_len_temp*2;
	}

	return  ret;
}

void silk_decoder_stop()
{
	if(m_pSilkDec){
		free( m_pSilkDec);
		m_pSilkDec = NULL;
	}
}
