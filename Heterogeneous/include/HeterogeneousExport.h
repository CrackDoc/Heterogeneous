#ifndef HeterogeneousExport_h__
#define HeterogeneousExport_h__

#if defined(WIN32)
#ifdef  Heterogeneous_EXPORTS
#define Heterogeneous_EXPORT __declspec(dllexport)
#else
#define  Heterogeneous_EXPORT __declspec(dllimport)
#endif

#pragma warning( disable: 4251 )

#elif __linux__
#define Heterogeneous_EXPORT

#else
#define Heterogeneous_EXPORT 
#endif
#endif // ExtendStructureExport_h__
