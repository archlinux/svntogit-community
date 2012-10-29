# $Id: PKGBUILD 69719 2012-04-23 02:56:20Z svenstaro $
# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
pkgname=cuda
pkgver=5.0.35
pkgrel=2
pkgdesc="NVIDIA's GPU programming toolkit"
arch=('i686' 'x86_64')
url="http://www.nvidia.com/object/cuda_home.html"
license=('custom')
depends=('gcc-libs' 'opencl-nvidia')
replaces=('cuda-toolkit' 'cuda-sdk')
provides=('cuda-toolkit' 'cuda-sdk')
optdepends=('gdb: for cuda-gdb')
options=(!strip)
if [ "$CARCH" = "i686" ]; then
  _arch=32
  md5sums=('40c514acb750902c54656b97a6deded6'
           '7e5990e03eea90075f5a500e91a0c3d3'
           'c0781c63e726eaf03e10135b42b85729')
else
  _arch=64
  md5sums=('df796fb9ab66075b5c346b3fd0bf596b'
           '7e5990e03eea90075f5a500e91a0c3d3'
           'c0781c63e726eaf03e10135b42b85729')
fi
install=cuda.install
source=(http://developer.download.nvidia.com/compute/cuda/5_0/rel-update-1/installers/cuda_${pkgver}_linux_${_arch}_fedora16-1.run
        cuda.sh
        cuda.conf)

build() {
  cd "$srcdir"
}

package() {
  sh cuda_${pkgver}_linux_${_arch}_fedora16-1.run -toolkitpath=$PWD -samplespath=$PWD -extract=$srcdir
  ./cudatoolkit_${pkgver}_linux_${_arch}_fedora16.run -prefix=$pkgdir/opt/cuda -noprompt
  ./cuda-samples_${pkgver}_linux.run -cudaprefix=$pkgdir/opt/cuda -prefix=$pkgdir/opt/cuda/samples -noprompt

  # allow gcc 4.7 to work
  sed -i "/unsupported GNU/d" $pkgdir/opt/cuda/include/host_config.h

  # fix nvidia path fuckup
  sed -i "s|/build/pkg||g" $pkgdir/opt/cuda/bin/nvvp

  install -Dm755 cuda.sh $pkgdir/etc/profile.d/cuda.sh
  install -Dm644 cuda.conf $pkgdir/etc/ld.so.conf.d/cuda.conf

  install -Dm644 $pkgdir/opt/cuda/doc/EULA.txt $pkgdir/usr/share/licenses/$pkgname/LICENSE

  # correct cuda path in samples
  cd $pkgdir/opt/cuda/samples
  find . -type f | egrep -v '(ppm|pgm)' | xargs grep -lI "$pkgdir/opt/cuda" | xargs sed -i "s|$pkgdir/opt/cuda|/opt/cuda|g"
}
