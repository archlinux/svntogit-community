# $Id: PKGBUILD 69719 2012-04-23 02:56:20Z svenstaro $
# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
pkgname=cuda
pkgver=5.0.35
pkgrel=1
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
  md5sums=('eeae7f67ba6b3513d5676885b74ea1db'
           '7e5990e03eea90075f5a500e91a0c3d3'
           'c0781c63e726eaf03e10135b42b85729')
else
  _arch=64
  md5sums=('0ffd4b374c9974b1045ef58839dfea7c'
           '7e5990e03eea90075f5a500e91a0c3d3'
           'c0781c63e726eaf03e10135b42b85729')
fi
install=cuda.install
source=(http://developer.download.nvidia.com/compute/cuda/5_0/rel/installers/cuda_${pkgver}_linux_${_arch}_fedora16.run
        cuda.sh
        cuda.conf)

build() {
  cd "$srcdir"
}

package() {
  sh cuda_${pkgver}_linux_${_arch}_fedora16.run -toolkitpath=$PWD -samplespath=$PWD -extract=$srcdir
  ./cudatoolkit_${pkgver}_linux_${_arch}_fedora16.run -prefix=$pkgdir/opt/cuda -noprompt
  ./cuda-samples_${pkgver}_linux.run -cudaprefix=$pkgdir/opt/cuda -prefix=$pkgdir/opt/cuda/samples -noprompt

  install -Dm755 cuda.sh $pkgdir/etc/profile.d/cuda.sh
  install -Dm644 cuda.conf $pkgdir/etc/ld.so.conf.d/cuda.conf

  install -Dm644 $pkgdir/opt/cuda/doc/EULA.txt $pkgdir/usr/share/licenses/$pkgname/LICENSE

  # correct cuda path in samples
  cd $pkgdir/opt/cuda/samples
  find . -type f | egrep -v '(ppm|pgm)' | xargs grep -lI "$pkgdir/opt/cuda" | xargs sed -i "s|$pkgdir/opt/cuda|/opt/cuda|g"
}
