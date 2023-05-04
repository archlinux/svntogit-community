# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bruno Galeotti <bgaleotti at gmail dot com>

_pkgname=requests-aws4auth
pkgname=python-requests-aws4auth
pkgver=1.2.3
pkgrel=1
pkgdesc='Amazon Web Services version 4 authentication for the Python Requests module'
url='https://github.com/sam-washington/requests-aws4auth'
arch=('any')
license=('MIT')
depends=('python' 'python-requests' 'python-six')
makedepends=('python-setuptools' 'python-build' 'python-installer' 'python-wheel')
checkdepends=('python-pytest' 'python-httpx')
optdepends=('python-httpx')
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('5a0e941999ef90118530e7864ed34c688d9b723af7ed22c74c6d8c4692e844c6b02c3710a2cdbdfa3e607587847fe02f17d9db7c6d746b81256c78d8fa85300f')
b2sums=('1dfa3678ac73afa3d275fc183335cb5e8a2791ae553752e4e86913e55e19cacf3930ef84b2a1cfedf4d06ae9b933ccffa2951ad7289aa235e3c66782d3fbff0d')

prepare() {
  cd ${_pkgname}-${pkgver}
  sed '/./{H;$!d} ; x ; s/package_data=.*\n.*]},\n//' -i setup.py
}

build() {
  cd ${_pkgname}-${pkgver}
  python -m build --wheel --no-isolation
}

check() {
  cd ${_pkgname}-${pkgver}
  python -m pytest -k 'not test_headers_amz_example'
}

package() {
  cd ${_pkgname}-${pkgver}
  python -m installer --destdir="${pkgdir}" dist/*.whl
  install -Dm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
}

# vim: ts=2 sw=2 et:
