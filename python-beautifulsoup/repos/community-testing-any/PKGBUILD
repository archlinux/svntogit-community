# $Id$
# Maintainer: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: phrakture < aaron m griffin * gmail::com >
# Contributor: tardo <tardo@nagi-fanboi.net>

pkgname=python-beautifulsoup
pkgver=3.2.0
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
md5sums=('ef1e78f7689ea61314f7bddebcfde88c')

build() {
    cd "$srcdir/BeautifulSoup-$pkgver"
    python2 setup.py install --root="$pkgdir" -O1
}
