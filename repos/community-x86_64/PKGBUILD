# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Nils Christopher Brause <nilschrbrause@googlemail.com>
pkgname=waylandpp
pkgver=0.2.5
pkgrel=1
pkgdesc='Wayland C++ bindings'
arch=('x86_64')
url='https://github.com/NilsBrause/waylandpp'
license=('MIT' 'GPL3')
depends=(wayland 'pugixml')
conflicts=(waylandpp-git)
makedepends=(cmake egl-wayland)
source=("https://github.com/NilsBrause/waylandpp/archive/$pkgver.zip")
sha512sums=('d23e65bdf3daf622aea053a63b2a3f257b66b5537a1f84e9981eb9b8deda5f9d70a08ab2acccbf103a3b6205c24cd947053b85236d675dfe6004249ebb83b86d')

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
