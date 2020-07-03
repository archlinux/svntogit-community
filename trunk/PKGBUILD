# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Nils Christopher Brause <nilschrbrause@googlemail.com>
pkgname=waylandpp
pkgver=0.2.8
pkgrel=1
pkgdesc='Wayland C++ bindings'
arch=('x86_64')
url='https://github.com/NilsBrause/waylandpp'
license=('MIT' 'GPL3')
depends=(wayland 'pugixml')
conflicts=(waylandpp-git)
makedepends=(cmake egl-wayland)
source=("https://github.com/NilsBrause/waylandpp/archive/$pkgver.zip")
sha512sums=('00cf7ec9cbd45a78d4b344d619746738a8a292a56ea7ca6a148d2e460d2c03baf49fac0de642e017f6d7226c80e3e4400469b764d2c7be4b42e90ada68263aa2')

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
