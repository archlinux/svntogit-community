# Maintainer: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: phrakture < aaron m griffin * gmail::com >
# Contributor: tardo <tardo@nagi-fanboi.net>

pkgname=python-beautifulsoup
pkgver=3.0.8.1
pkgrel=1
pkgdesc="A Python HTML/XML parser designed for quick turnaround projects like screen-scraping"
arch=('any')
url="http://www.crummy.com/software/BeautifulSoup/index.html"
license=('PSF')
depends=('python2')
provides=('beautiful-soup')
conflicts=('beautiful-soup')
replaces=('beautiful-soup')
options=('force')
source=(http://www.crummy.com/software/BeautifulSoup/download/3.x/BeautifulSoup-$pkgver.tar.gz)
md5sums=('d2f7b6b25bd26cd15e8b8a60ecc49c90')

build() {
    cd "$srcdir/BeautifulSoup-$pkgver"
    python2 setup.py install --root="$pkgdir" -O1
}
