# Maintainer: BlackEagle <ike.devolder@gmail.com>>

pkgname=kodi-platform
_commit=809c5e9
pkgver=20190726.809c5e9
pkgrel=11
pkgdesc="platform library for external kodi addons"
arch=('x86_64')
url='https://github.com/xbmc/kodi-platform'
license=('GPL')
depends=('kodi' 'p8-platform')
makedepends=('git' 'cmake' 'kodi-dev')
source=("$pkgname::git://github.com/xbmc/kodi-platform.git#commit=$_commit")
sha256sums=('SKIP')

pkgver() {
    cd "$pkgname"
    git log -1 --date=short --format="%cd.%h" | tr -d '-'
}

build() {
    cd "$pkgname"
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=1 \
        -DUSE_LTO=1 \
        .
    make
}

package() {
    cd "$pkgname"
    make DESTDIR="$pkgdir/" install
}

