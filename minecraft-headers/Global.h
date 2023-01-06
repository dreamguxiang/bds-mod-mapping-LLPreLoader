#pragma once
#pragma warning(disable : 4250)
#pragma warning(disable : 4949)


#ifndef NOMINMAX
#define NOMINMAX
#endif // NOMINMAX

#ifndef LIAPI
#ifdef LITELOADER_EXPORTS
#define LIAPI __declspec(dllexport)
#else
#define LIAPI __declspec(dllimport)
#endif
#endif

#define MCAPI __declspec(dllimport)
#define MCVAPI __declspec(dllimport)
#define MCINLINE inline
#define MCCLS


