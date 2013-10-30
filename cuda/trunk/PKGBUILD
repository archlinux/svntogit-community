# $Id: PKGBUILD 69719 2012-04-23 02:56:20Z svenstaro $
# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
pkgname=cuda
pkgver=5.5.22
pkgrel=1
pkgdesc="NVIDIA's GPU programming toolkit"
arch=('x86_64')
url="http://www.nvidia.com/object/cuda_home.html"
license=('custom')
depends=('gcc-libs' 'opencl-nvidia')
replaces=('cuda-toolkit' 'cuda-sdk')
provides=('cuda-toolkit' 'cuda-sdk')
optdepends=('gdb: for cuda-gdb')
options=(!strip staticlibs)
md5sums=('7bb06908bdf33eac0f8426821640c2fb'
         '7e5990e03eea90075f5a500e91a0c3d3'
         'ffe1e6fb7f97b23da28fd94a5fd7356d')
install=cuda.install
source=(http://developer.download.nvidia.com/compute/cuda/5_5/rel/installers/cuda_${pkgver}_linux_64.run
        cuda.sh
        cuda.conf)

package() {
  sh cuda_${pkgver}_linux_64.run -extract=$srcdir
  ./cuda-linux64-rel-${pkgver}*.run -prefix=$pkgdir/opt/cuda -noprompt
  ./cuda-samples-linux-${pkgver}*.run -cudaprefix=$pkgdir/opt/cuda -prefix=$pkgdir/opt/cuda/samples -noprompt

  # Now, let the hacks begin!

  # allow newer gcc to work
  # NOTE: We don't need these currently, but we might again! :D
  #sed -i "/unsupported GNU/d" $pkgdir/opt/cuda/include/host_config.h
  #sed -i "1 i #define __STRICT_ANSI__" $pkgdir/opt/cuda/include/cuda_runtime.h
  #echo "#undef _GLIBCXX_ATOMIC_BUILTINS" >> $pkgdir/opt/cuda/include/cuda_runtime.h
  #echo "#define _GLIBCXX_GTHREAD_USE_WEAK 0" >> $pkgdir/opt/cuda/include/cuda_runtime.h

  # fix nvidia path fuckup
  #sed -i "s|/build/pkg/cuda||g" $pkgdir/opt/cuda/bin/nvvp $pkgdir/opt/cuda/bin/nsight

  install -Dm755 $srcdir/cuda.sh $pkgdir/etc/profile.d/cuda.sh
  install -Dm644 $srcdir/cuda.conf $pkgdir/etc/ld.so.conf.d/cuda.conf

  # correct cuda path in samples
  cd $pkgdir/opt/cuda/samples
  find . -name Makefile | xargs sed -i "s|$pkgdir/opt/cuda|/opt/cuda|g"

  # make cuda-gdk work
  mkdir -p $pkgdir/usr/lib
  cd $pkgdir/usr/lib
  ln -s /usr/lib/libncurses.so.5 libtinfo.so.5
}
