# Maintainer : Daniel Bermond <dbermond@archlinux.org>
# Contributor: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Laurent Carlier <lordheavym@gmail.com>
# Contributor: Allan McRae <allan@archlinux.org>
# Contributor: Zephyr

pkgname=mupen64plus
pkgver=2.5
pkgrel=24
pkgdesc='Nintendo64 Emulator'
arch=('x86_64')
url='https://github.com/mupen64plus/mupen64plus-core'
license=('GPL')
depends=('boost-libs' 'freetype2' 'glu' 'libgl' 'libpng' 'libsamplerate' 'sdl'
         'zlib' 'hicolor-icon-theme')
makedepends=('boost' 'mesa')
source=("https://github.com/mupen64plus/mupen64plus-core/releases/download/${pkgver}/mupen64plus-bundle-src-${pkgver}.tar.gz"
        '010-mupen64plus-ui-console-pie.patch'
        '020-mupen64plus-core-gcc10-fix.patch'
        '030-mupen64plus-sdl12-compat-fix.patch'::'https://github.com/mupen64plus/mupen64plus-core/commit/5a5ffc0c78b0e255f54b15d2480f617d5cbc33ec.patch')
sha256sums=('9c75b9d826f2d24666175f723a97369b3a6ee159b307f7cc876bbb4facdbba66'
            '0b674779949ca90db9f156b56dd9d7be9847354f5b07ec73aa3a89dde79d6b6d'
            'f84f262bcf2b748ccded4443735caba92926241f9238f545a621009f6ae64ef7'
            '1de522155742fd493075d051855e420a9bc98af2f4774ecb66b4fdef69a7adc4')

prepare() {
    patch -d "mupen64plus-bundle-src-${pkgver}" -Np1 -i "${srcdir}/010-mupen64plus-ui-console-pie.patch"
    patch -d "mupen64plus-bundle-src-${pkgver}" -Np1 -i "${srcdir}/020-mupen64plus-core-gcc10-fix.patch"
    patch -d "mupen64plus-bundle-src-${pkgver}/source/mupen64plus-core" -Np1 -i "${srcdir}/030-mupen64plus-sdl12-compat-fix.patch"
}

build() {
    cd "mupen64plus-bundle-src-${pkgver}"
    ./m64p_build.sh
}

package() {
    cd "mupen64plus-bundle-src-${pkgver}"
    
    # set LDCONFIG since we are using fakeroot and scripts run root commands by checking the uid
    ./m64p_install.sh DESTDIR="$pkgdir" PREFIX='/usr' LDCONFIG='true'
    
    local _sover
    _sover="$(find "${pkgdir}/usr/lib" -type f -name 'libmupen64plus.so.*.*.*' | sed 's/^.*\.so\.//')"
    ln -s "libmupen64plus.so.${_sover}" "${pkgdir}/usr/lib/libmupen64plus.so"
}
