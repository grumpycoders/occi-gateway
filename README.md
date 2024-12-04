# What is OCCI-gateway ?
OCCI-gateway is intended to be a Windows DLL acting as a glue between the Oracle's OCCI DLL and your software.
# Why is such gateway even needed ?
The ORAOCCI11.DLL is compiled using VC8 or VC9, and is written in C++. C++ is a terrible language, especially when it comes to exporting code to other pieces of software. A DLL containing exported C++ code can only work with a software that's compiled using the same compiler. Since the OCCI DLL in the Oracle 11g installation is compiled using VC8 or VC9, you can only have code running against this DLL compiled using VC8 or VC9. Worse: the DLL which is shipped by default in the client is compiled using VC8. So if you don't want to have to ship the DLL with your software, you HAVE to use Visual Studio 2005 to compile your code.
# How does the gateway work ?
The gateway works in two parts. One DLL which is called OCCI-MSVCgateway.dll, coming from the file OCCI-MSVCgateway.cpp, and compiled using Microsoft Visual Studio 2005 Express, and one static cpp file called OCCI-mingw32gateway.cpp, which can be compiled using any compiler (despite its name). The MSVC portion of the code is downgrading the OCCI C++ calls down to a plain-C interface, and the mingw32 portion of the code upgrades it back to C++. So the communication between your software and OCCI-MSVCgateway.dll is done in plain C, which is always compatible whatever compiler you're using.
# So this only works for mingw32 ?
I haven't tested otherwise, but there's no reason why this shouldn't work for other compilers, especially Microsoft Visual Studio 2010. My current software is compiled using mingw32, and works beautifully.
# Is all of OCCI translated ?
No. I've only translated and proxified the OCCI calls I needed for my own software, but that's still quite a lot. And I'll add more when the needs come, or if people submit patches my way.
# What's the license of this software ?
I haven't really put any. BSD I guess. Or public domain. If that really matters to you, consider I'm licensing it the way you want. I hereby allow you to sub-license this code to any license you want. Of course, anything that doesn't imply any warranty from my end. This software Works For Me, but it might crash your computer, induce data loss, eat babies and melt your face. I'm not responsible for any of this.
# Allright, how do I use this code ?
Here's how my own code is doing:
```
#ifdef __MINGW32__
#include "OCCI-proxy.h"
#define ORAPREFIX occi_proxy
#else
#include <occi.h>
#define ORAPREFIX oracle::occi
#endif
using namespace ORAPREFIX;
```

And that's about it! The OCCI-proxy.h fakes most of the OCCI classes, inside the occi_proxy namespace. So just swap oracle::occi for occi_proxy, and load OCCI-proxy.h instead of occi.h, and you're done!
# Isn't that software pointless ? Why not recoding your own OCI glue instead of using Oracle's ?
Because that'd require me to fully understand OCI, which I don't want to. This software is mostly copy-and-paste, and a no-brainer to me.
# If it was so mechanical to write that code, why not writing a generic parser that'd convert C++ code ?
That might have been an option. A SWIG parser for example, that'd generate all the necessary files. But I think this is so fragile that it required hand-crafting. However, this is a good proof-of-concept that this might actually be doable generically.
# I don't have Microsoft Visual Studio 2005 Express installed. Is there any pre-compiled version of your DLL?
[Yes, here.](http://static.grumpycoder.net/pixel/OCCI-MSVCgateway.zip)
# Is this software robust ?
Yes and no. I've tried to be quite consistent and proper in my coding, so that part should be quite robust. However, the trick it involves is pretty shady, so that part is very fragile. For instance, I've never managed to get this working with the instantclient, only the full oracle client. And only with Visual Studio 2005 (vc8). But it seems that once you get the basics working, everything works pretty smoothly, minus my local mistakes and typos, of course. Don't hesitate to forward me bugs and typos I may have committed.
# Authors
Main author: Nicolas "Pixel" Noble, pixel [at] grumpycoder.net  
Contributors: Bill Lowrey
