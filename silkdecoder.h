#ifndef 	SILKDECODER_H_
#define 	SILKDECODER_H_

int 	silk_decoder_start(int sampleRate);
int 	silk_decoder_decode(unsigned char* inbuf, short inlen, unsigned char* outbuf, short out_len);
void 	silk_decoder_stop();

#endif /* SILKDECODER_H_ */