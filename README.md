flash_silk
==========

I spend two days to make SILK works for Flash, compile it with FLasCC and provide a Flash swc to use by projects.
I'm going to share this, to save other people's time. 

Using the libaudiocodec.swc will be enough for decode purpose, but if you need to customize parameters, install FlasCC, modify and recompile with:
make lib FLASCC=/path/to/flascc FLEX=/path/to/flex.

If the make failed, please read Makefile.common, there is a hardcode asc2.jar full path.
