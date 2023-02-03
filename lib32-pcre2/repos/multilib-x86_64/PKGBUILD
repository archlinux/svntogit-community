
pkgname=lib32-pcre2
_pkgname=pcre2
pkgver=10.42
pkgrel=1
pkgdesc='A library that implements Perl 5-style regular expressions. 2nd version (32-bit)'
arch=('x86_64')
url='https://www.pcre.org/'
license=('BSD')
depends=('lib32-gcc-libs' "$_pkgname")
provides=(libpcre2-{8,16,32,posix}.so)
source=("https://github.com/PhilipHazel/pcre2/releases/download/$_pkgname-$pkgver/$_pkgname-$pkgver.tar.bz2"{,.sig})
sha512sums=('72fbde87fecec3aa4b47225dd919ea1d55e97f2cbcf02aba26e5a0d3b1ffb58c25a80a9ef069eb99f9cf4e41ba9604ad06a7ec159870e1e875d86820e12256d3'
            'SKIP')
validpgpkeys=('45F68D54BBE23FB3039B46E59766E084FB0F43D8')  # Philip Hazel <ph10@hermes.cam.ac.uk>

build() {
  cd $_pkgname-$pkgver

  export CC="gcc -m32"
  export CXX="g++ -m32"
  export PKG_CONFIG="i686-pc-linux-gnu-pkg-config"

  ./configure \
    --prefix=/usr \
    --libdir=/usr/lib32 \
    --enable-pcre2-16 \
    --enable-pcre2-32 \
    --enable-jit \
    --disable-pcre2grep-libz \
    --disable-pcre2grep-libbz2 \
    --disable-pcre2test-libreadline
  make
}

check() {
  cd $_pkgname-$pkgver
  make -j1 check
}

package() {
  cd $_pkgname-$pkgver
  make DESTDIR="$pkgdir" install
  rm -r "$pkgdir"/usr/{bin,share,include}

  install -Dm644 LICENCE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set sw=2 sts=-1 et:
