# Maintainer: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: phrakture < aaron m griffin * gmail::com >
# Contributor: tardo <tardo@nagi-fanboi.net>

pkgname=beautiful-soup
pkgver=3.1.0.1
pkgrel=4
pkgdesc="A Python HTML/XML parser designed for quick turnaround projects like screen-scraping"
arch=('any')
url="http://www.crummy.com/software/BeautifulSoup/index.html"
license=('PSF')
depends=('python2')
source=(http://www.crummy.com/software/BeautifulSoup/download/3.1.x/BeautifulSoup-$pkgver.tar.gz)
md5sums=('69ec3a99c8a2bf2fc03ff6ccaae58491')

build() {
    cd "$srcdir/BeautifulSoup-$pkgver"
    python2 setup.py install --root="$pkgdir" -O1
}
