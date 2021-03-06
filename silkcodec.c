/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.4
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif 
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif



#include <stdlib.h>
#include <string.h>
#include "AS3/AS3.h"
#define swig_as3(X) inline_as3("import com.adobe.flascc.swig.*; " X)


/* Contract support */

#define SWIG_contract_assert(expr, msg) if (!(expr)) {int msglen = strlen(msg);__asm__ volatile ("throw new Exception(CModule.readString(%0, %1))": : "r"(msg), "r"(msglen));}


__attribute__((annotate("as3sig:public function _wrap_silk_decoder_start(sampleRate:int):int")))
void _wrap_silk_decoder_start() {
  int arg1 ;
  int result ;
  
  {
    AS3_GetScalarFromVar(arg1, sampleRate);
  }
  result = (int)silk_decoder_start(arg1);
  {
    AS3_DeclareVar(asresult, int);
    AS3_CopyScalarToVar(asresult, result);
  }
  {
    AS3_ReturnAS3Var(asresult);
  }
}


__attribute__((annotate("as3sig:public function _wrap_silk_decoder_decode(inbuf:int, inlen:int, outbuf:int, out_len:int):int")))
void _wrap_silk_decoder_decode() {
  unsigned char *arg1 = (unsigned char *) 0 ;
  short arg2 ;
  unsigned char *arg3 = (unsigned char *) 0 ;
  short arg4 ;
  int result ;
  
  {
    AS3_GetScalarFromVar(arg1, inbuf);
  }
  {
    AS3_GetScalarFromVar(arg2, inlen);
  }
  {
    AS3_GetScalarFromVar(arg3, outbuf);
  }
  {
    AS3_GetScalarFromVar(arg4, out_len);
  }
  result = (int)silk_decoder_decode(arg1,arg2,arg3,arg4);
  {
    AS3_DeclareVar(asresult, int);
    AS3_CopyScalarToVar(asresult, result);
  }
  {
    AS3_ReturnAS3Var(asresult);
  }
}


__attribute__((annotate("as3sig:public function _wrap_silk_decoder_stop():void")))
void _wrap_silk_decoder_stop() {
  silk_decoder_stop();
  {
    
  }
  {
    AS3_ReturnAS3Var(undefined);
  }
}


__attribute__((annotate("as3sig:public function _wrap_silk_encoder_start(sampleRate:int, channels:int, quality:int):int")))
void _wrap_silk_encoder_start() {
  int arg1 ;
  int arg2 ;
  int arg3 ;
  int result ;
  
  {
    AS3_GetScalarFromVar(arg1, sampleRate);
  }
  {
    AS3_GetScalarFromVar(arg2, channels);
  }
  {
    AS3_GetScalarFromVar(arg3, quality);
  }
  result = (int)silk_encoder_start(arg1,arg2,arg3);
  {
    AS3_DeclareVar(asresult, int);
    AS3_CopyScalarToVar(asresult, result);
  }
  {
    AS3_ReturnAS3Var(asresult);
  }
}


__attribute__((annotate("as3sig:public function _wrap_silk_encoder_encode(inbuf:int, inlen:int, outbuf:int, out_len:int):int")))
void _wrap_silk_encoder_encode() {
  unsigned char *arg1 = (unsigned char *) 0 ;
  short arg2 ;
  unsigned char *arg3 = (unsigned char *) 0 ;
  short arg4 ;
  int result ;
  
  {
    AS3_GetScalarFromVar(arg1, inbuf);
  }
  {
    AS3_GetScalarFromVar(arg2, inlen);
  }
  {
    AS3_GetScalarFromVar(arg3, outbuf);
  }
  {
    AS3_GetScalarFromVar(arg4, out_len);
  }
  result = (int)silk_encoder_encode(arg1,arg2,arg3,arg4);
  {
    AS3_DeclareVar(asresult, int);
    AS3_CopyScalarToVar(asresult, result);
  }
  {
    AS3_ReturnAS3Var(asresult);
  }
}


__attribute__((annotate("as3sig:public function _wrap_silk_encoder_stop():void")))
void _wrap_silk_encoder_stop() {
  silk_encoder_stop();
  {
    
  }
  {
    AS3_ReturnAS3Var(undefined);
  }
}


__attribute__((annotate("as3sig:public function _wrap_speex_encoder_start(sample_rate:int):void")))
void _wrap_speex_encoder_start() {
  int arg1 ;
  
  {
    AS3_GetScalarFromVar(arg1, sample_rate);
  }
  speex_encoder_start(arg1);
  {
    
  }
  {
    AS3_ReturnAS3Var(undefined);
  }
}


__attribute__((annotate("as3sig:public function _wrap_speex_encoder_encode(src:int, len:int, out:int, outlen:int):int")))
void _wrap_speex_encoder_encode() {
  unsigned char *arg1 = (unsigned char *) 0 ;
  int arg2 ;
  unsigned char *arg3 = (unsigned char *) 0 ;
  int arg4 ;
  int result ;
  
  {
    AS3_GetScalarFromVar(arg1, src);
  }
  {
    AS3_GetScalarFromVar(arg2, len);
  }
  {
    AS3_GetScalarFromVar(arg3, out);
  }
  {
    AS3_GetScalarFromVar(arg4, outlen);
  }
  result = (int)speex_encoder_encode(arg1,arg2,arg3,arg4);
  {
    AS3_DeclareVar(asresult, int);
    AS3_CopyScalarToVar(asresult, result);
  }
  {
    AS3_ReturnAS3Var(asresult);
  }
}


__attribute__((annotate("as3sig:public function _wrap_speex_encoder_stop():void")))
void _wrap_speex_encoder_stop() {
  speex_encoder_stop();
  {
    
  }
  {
    AS3_ReturnAS3Var(undefined);
  }
}


__attribute__((annotate("as3sig:public function _wrap_speex_decoder_start(sample_rate:int):void")))
void _wrap_speex_decoder_start() {
  int arg1 ;
  
  {
    AS3_GetScalarFromVar(arg1, sample_rate);
  }
  speex_decoder_start(arg1);
  {
    
  }
  {
    AS3_ReturnAS3Var(undefined);
  }
}


__attribute__((annotate("as3sig:public function _wrap_speex_decoder_decode(src:int, len:int, out:int, outlen:int):int")))
void _wrap_speex_decoder_decode() {
  unsigned char *arg1 = (unsigned char *) 0 ;
  int arg2 ;
  unsigned char *arg3 = (unsigned char *) 0 ;
  int arg4 ;
  int result ;
  
  {
    AS3_GetScalarFromVar(arg1, src);
  }
  {
    AS3_GetScalarFromVar(arg2, len);
  }
  {
    AS3_GetScalarFromVar(arg3, out);
  }
  {
    AS3_GetScalarFromVar(arg4, outlen);
  }
  result = (int)speex_decoder_decode(arg1,arg2,arg3,arg4);
  {
    AS3_DeclareVar(asresult, int);
    AS3_CopyScalarToVar(asresult, result);
  }
  {
    AS3_ReturnAS3Var(asresult);
  }
}


__attribute__((annotate("as3sig:public function _wrap_speex_decoder_stop():void")))
void _wrap_speex_decoder_stop() {
  speex_decoder_stop();
  {
    
  }
  {
    AS3_ReturnAS3Var(undefined);
  }
}


