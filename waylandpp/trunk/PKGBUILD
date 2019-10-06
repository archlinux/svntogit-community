# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Nils Christopher Brause <nilschrbrause@googlemail.com>
pkgname=waylandpp
pkgver=0.2.6
pkgrel=1
pkgdesc='Wayland C++ bindings'
arch=('x86_64')
url='https://github.com/NilsBrause/waylandpp'
license=('MIT' 'GPL3')
depends=(wayland 'pugixml')
conflicts=(waylandpp-git)
makedepends=(cmake egl-wayland)
source=("https://github.com/NilsBrause/waylandpp/archive/$pkgver.zip")
sha512sums=('bb5cbee492502db14b4052bfbc07186f0845bbfbc2261722b70045e748d5db7237a83439fe36cf49c707ca4d4008f750910656b7638e48fe7a032162c73038a1')

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
