# $Id$
# Maintainer: Ronald van Haren <ronald@archlinux.org>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: phrakture < aaron m griffin * gmail::com >
# Contributor: tardo <tardo@nagi-fanboi.net>

pkgname=python-beautifulsoup
pkgver=3.2.0
pkgrel=2
pkgdesc="A Python HTML/XML parser designed for quick turnaround projects like screen-scraping"
arch=('any')
url="http://www.crummy.com/software/BeautifulSoup/index.html"
license=('PSF')
depends=('python2')
provides=('beautiful-soup')
conflicts=('beautiful-soup')
replaces=('beautiful-soup')
source=(http://www.crummy.com/software/BeautifulSoup/download/3.x/BeautifulSoup-$pkgver.tar.gz)
sha1sums=('924eb4e43144e233e3749edadc8dc5cd8ec8a3be')

build() {
    cd "$srcdir/BeautifulSoup-$pkgver"
    python2 setup.py install --root="$pkgdir" -O1
}
