# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Nils Christopher Brause <nilschrbrause@googlemail.com>
pkgname=waylandpp
pkgver=0.2.7
pkgrel=1
pkgdesc='Wayland C++ bindings'
arch=('x86_64')
url='https://github.com/NilsBrause/waylandpp'
license=('MIT' 'GPL3')
depends=(wayland 'pugixml')
conflicts=(waylandpp-git)
makedepends=(cmake egl-wayland)
source=("https://github.com/NilsBrause/waylandpp/archive/$pkgver.zip")
sha512sums=('35ff3fd23af7b156fa2d7dcbf571661e5196c92e52d800ee1901ce75ea4eb2b83a5f51a6c6ec67eea886c7016f13a28035b3bb4ccc2c6323cc0126aa8ac59ab2')

build()
{
    cd $pkgname-$pkgver
    [[ -d build ]] && rm -rf build
    mkdir build
    cd build
    # lib64 is a symlink to lib on archlinux.
    cmake -DCMAKE_INSTALL_PREFIX="/usr" -DCMAKE_INSTALL_LIBDIR="lib" .. 
    make
}

package()
{
    cd $pkgname-$pkgver/build
    DESTDIR="$pkgdir" make install
}
