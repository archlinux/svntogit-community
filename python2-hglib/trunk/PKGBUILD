# Contributor: Erik Johnson <palehose at gmail dot com>

pkgname=python2-hglib
_realname=python-hglib
pkgver=1.5
pkgrel=1
pkgdesc="python-hglib is a library with a fast, convenient interface to Mercurial. It uses Mercurial's command server for communication with hg."
arch=('any')
url="https://pypi.python.org/pypi/python-hglib"
license=('MIT')
depends=('python2' 'mercurial')
source=("https://pypi.python.org/packages/source/p/python-hglib/${_realname}-${pkgver}.tar.gz")
md5sums=('47bddc41ade625ff977d811a4ea57724')

build() {
  cd "${srcdir}/${_realname}-${pkgver}"
  python2 setup.py build
}

package() {
  cd "${srcdir}/${_realname}-${pkgver}"
  python2 setup.py install --root=${pkgdir}
}
