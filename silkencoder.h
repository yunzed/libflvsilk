#ifndef 	SILKENCODER_H_
#define 	SILKENCODER_H_

int 	silk_encoder_start(int sampleRate, int channels, int quality);
int 	silk_encoder_encode(unsigned char* inbuf, short inlen, unsigned char* outbuf, short out_len);
void 	silk_encoder_stop();

#endif /* SILKENCODER_H_ */