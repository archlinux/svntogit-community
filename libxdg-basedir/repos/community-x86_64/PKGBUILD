# Maintainer: Ronald van Haren <ronald.archlinux.org>
# Contributor: Ondrej Martinak <omartinak@gmail.com>

pkgname=libxdg-basedir
pkgver=1.2.3
pkgrel=1
pkgdesc="An implementation of the XDG Base Directory specifications."
arch=('x86_64')
#url="http://n.ethz.ch/student/nevillm/download/libxdg-basedir"
url="https://github.com/devnev/$pkgname"
license=('MIT')
depends=('glibc')
source=(https://github.com/devnev/$pkgname/archive/$pkgname-$pkgver.tar.gz
        'LICENSE')
sha512sums=('e672da0d9cd3c27c9113f6053b79127e615e5d84bde81305242f506e930869d8492304aac26a0296528d5a32530e4a743acecb6a25f58372ac597af284429f7c'
            '772afb3c9aefe6ed6b941faf582ea74582c3e7042237701f7e02d4f237d3e4ec528ebc7caf5adb2c1a0adc398fae52e172c009ad962de0620b0376123d76b2d6')

build() {
   cd ${pkgname}-${pkgname}-${pkgver}
   ./autogen.sh
   ./configure --prefix=/usr
   make
}

package() {
   cd ${pkgname}-${pkgname}-${pkgver}
   make DESTDIR="${pkgdir}" install

   # Install MIT license
   install -Dm644 "${srcdir}"/LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}

