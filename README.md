# SRMD ncnn Vulkan

![CI](https://github.com/nihui/srmd-ncnn-vulkan/workflows/CI/badge.svg)

ncnn implementation of SRMD super resolution.

srmd-ncnn-vulkan uses [ncnn project](https://github.com/Tencent/ncnn) as the universal neural network inference framework.

## [Download](https://github.com/nihui/srmd-ncnn-vulkan/releases)

Download Windows/Linux/MacOS Executable for Intel/AMD/Nvidia GPU

**https://github.com/nihui/srmd-ncnn-vulkan/releases**

This package includes all the binaries and models required. It is portable, so no CUDA or Caffe runtime environment is needed :)

## Usages

### Example Command

```shell
srmd-ncnn-vulkan.exe -i input.jpg -o output.png -n 3 -s 2
```

### Full Usages

```console
Usage: srmd-ncnn-vulkan -i infile -o outfile [options]...

  -h                   show this help
  -v                   verbose output
  -i input-path        input image path (jpg/png/webp) or directory
  -o output-path       output image path (png) or directory
  -n noise-level       denoise level (-1/0/1/2/3/4/5/6/7/8/9/10, default=3)
  -s scale             upscale ratio (2/3/4, default=2)
  -t tile-size         tile size (>=32/0=auto, default=0)
  -m model-path        srmd model path (default=models-srmd)
  -g gpu-id            gpu device to use (default=0)
  -j load:proc:save    thread count for load/proc/save (default=1:2:2)
  -x                   enable tta mode
```

- `input-path` and `output-path` accept either file path or directory path
- `noise-level` = noise level, large value means strong denoise effect, -1=no effect
- `scale` = scale level, 2=upscale 2x
- `tile-size` = tile size, use smaller value to reduce GPU memory usage, default is auto
- `load:proc:save` = thread count for the three stages (image decoding + srmd upscaling + image encoding), use larger value may increase GPU utility and consume more GPU memory. You can tune this configuration as "4:4:4" for many small-size images, and "2:2:2" for large-size images. The default setting usually works fine for most situations. If you find that your GPU is hungry, do increase thread count to achieve faster processing.

If you encounter crash or error, try to upgrade your GPU driver

- Intel: https://downloadcenter.intel.com/product/80939/Graphics-Drivers
- AMD: https://www.amd.com/en/support
- NVIDIA: https://www.nvidia.com/Download/index.aspx

## Sample Images

### Original Image

![origin](images/0.jpg)

### Upscale 4x with ImageMagick Lanczo4 Filter

```shell
convert origin.jpg -resize 400% output.png
```

![browser](images/1.png)

### Upscale 4x with waifu2x scale=2 model=upconv_7_photo twice

```shell
waifu2x-ncnn-vulkan.exe -i origin.jpg -o 2x.png -s 2 -m models-upconv_7_photo
waifu2x-ncnn-vulkan.exe -i 2x.png -o 4x.png -s 2 -m models-upconv_7_photo
```

![waifu2x](images/w.png)

### Upscale 4x with srmd noise=3 scale=4

```shell
srmd-ncnn-vulkan.exe -i origin.jpg -o output.png -n 3 -s 4
```

![srmd](images/2.png)

## Original SRMD Project

- https://github.com/cszn/SRMD
- https://github.com/cszn/KAIR

## Other Open-Source Code Used

- https://github.com/Tencent/ncnn for fast neural network inference on ALL PLATFORMS
- https://github.com/nothings/stb for decoding and encoding image on Linux / MacOS
- https://github.com/tronkko/dirent for listing files in directory on Windows
- https://github.com/webmproject/libwebp for decoding Webp images on ALL PLATFORMS
