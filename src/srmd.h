// srmd implemented with ncnn library

#ifndef SRMD_H
#define SRMD_H

#include <string>

// ncnn
#include "net.h"
#include "gpu.h"

class SRMD
{
public:
    SRMD(int gpuid);
    ~SRMD();

#if _WIN32
    int load(const std::wstring& parampath, const std::wstring& modelpath);
#else
    int load(const std::string& parampath, const std::string& modelpath);
#endif

    int process(const ncnn::Mat& inimage, ncnn::Mat& outimage) const;

public:
    // srmd parameters
    int noise;
    int scale;
    int tilesize;
    int prepadding;

private:
    ncnn::Net net;
    ncnn::Pipeline* srmd_preproc;
    ncnn::Pipeline* srmd_postproc;
};

#endif // SRMD_H
