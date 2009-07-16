# $Id: PKGBUILD,v 1.4 2009/03/25 10:42:48 dsa Exp $
# Contributor: Peter Baldwin <bald_pete@hotmail.com>

pkgname=python-jinja
pkgver=2.1.1
pkgrel=1
pkgdesc="A simple pythonic template language written in Python"
license=("BSD")
url="http://jinja.pocoo.org/2/"
depends=('python')
source=(http://pypi.python.org/packages/source/J/Jinja2/Jinja2-$pkgver.tar.gz)
arch=('i686' 'x86_64')

build() {
  cd $startdir/src/Jinja2-$pkgver
  python setup.py install --root=$startdir/pkg
}
md5sums=('b37fc262e4f613eec57c3defe6aea97c')
