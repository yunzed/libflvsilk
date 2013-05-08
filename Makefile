include Makefile.common

TARGET = libflvsilk.swc


SRCS_C = $(wildcard silk/src/*.c) main.c silkdecoder.c silkencoder.c silkcodec.c


lib:
	"$(FLASCC)/usr/bin/swig" -as3 -module silkcodec -outdir . -includeall -ignoremissing -o silkcodec.c silkcodec.h
	echo "compile silkcodec.as"	
	$(AS3COMPILERARGS) -abcfuture -AS3 -import $(FLASCC_WINPATH)/sdk/usr/lib/builtin.abc -import $(FLASCC_WINPATH)/sdk/usr/lib/playerglobal.abc silkcodec.as
	
	echo "last step: link"
	"$(FLASCC)/usr/bin/gcc" -jvmopt=-Xmx1G $(BASE_CFLAGS) silkcodec.abc $(SRCS_C) -DHAVE_CONFIG_H -I ./ -I./silk/include -I./speex/include -I./speex -emit-swc=com.codec -o $(TARGET)
