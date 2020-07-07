# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname=tldp-howtos-txt
pkgver=20161114
pkgrel=3
pkgdesc="HOWTO's from tldp.org (one text file per howto)"
arch=('any')
url="http://tldp.org/"
license=("FDL")
depends=()
options=('docs')
source=(http://tldp.org/Linux-HOWTO-text.tar.gz)
sha256sums=('86ec7527d5a8c6225190c6fe20a7fdb5c69d910dd36d0ff6be349ae014b62b06')

package() {
    cd "$srcdir"
    mkdir -p "$pkgdir"/usr/share/doc/howto/txt
    rm -f .htaccess Linux-HOWTOs.tar.bz2
    mv * "$pkgdir"/usr/share/doc/howto/txt/
}
