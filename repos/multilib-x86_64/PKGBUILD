# Contributor: Pierre Schmitz <pierre@archlinux.de>
# Contributor: François Charette <firmicus@gmx.net>

pkgname=lib32-xz
pkgver=5.4.3
pkgrel=1
pkgdesc='Library and command line tools for XZ and LZMA compressed files (32-bit)'
arch=('x86_64')
url='https://tukaani.org/xz/'
license=('GPL' 'LGPL' 'custom')
depends=('lib32-glibc' 'xz')
provides=('liblzma.so')
validpgpkeys=('3690C240CE51B4670D30AD1C38EE757D69184620'  # Lasse Collin <lasse.collin@tukaani.org>
              '22D465F2B4C173803B20C6DE59FCF207FEA7F445') # Jia Tan <jiat0218@gmail.com>
source=("https://tukaani.org/xz/xz-${pkgver}.tar.gz"{,.sig})
sha256sums=('1c382e0bc2e4e0af58398a903dd62fff7e510171d2de47a1ebe06d1528e9b7e9'
            'SKIP')
sha512sums=('aff0fe166af6df4491a6f5df2372cab100b081452461a0e8c6fd65b72af3f250f16c64d9fb8fd309141e9b9ae4e41649f48687cc29e63dd82f27f2eab19b4023'
            'SKIP')

build() {
  cd "${srcdir}/xz-${pkgver}"

  export CC='gcc -m32'
  export PKG_CONFIG='i686-pc-linux-gnu-pkg-config'

  ./configure \
    --prefix=/usr \
    --libdir=/usr/lib32 \
    --disable-rpath \
    --enable-werror
  make
}

check() {
  cd "${srcdir}/xz-${pkgver}"

  make check
}

package() {
  cd "${srcdir}/xz-${pkgver}"

  make DESTDIR="${pkgdir}" install

  rm -rf "${pkgdir}"/usr/{bin,include,share}
  install -d -m0755 "${pkgdir}"/usr/share/licenses
  ln -s xz "${pkgdir}"/usr/share/licenses/lib32-xz
}
