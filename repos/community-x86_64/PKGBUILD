# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Timothée Ravier <tim@siosm.fr>

_name=dulwich
pkgname=python-dulwich
pkgver=0.21.5
pkgrel=1
pkgdesc='Pure-Python implementation of the Git file formats and protocols'
arch=('x86_64')
url=https://www.dulwich.io
license=('GPL')
depends=('python-urllib3')
makedepends=('python-build' 'python-installer' 'python-setuptools'
             'python-wheel')
checkdepends=('python-gpgme' 'python-paramiko')
optdepends=('python-fastimport: for fast-import support'
            'python-gpgme: for PGP signature support'
            'python-idna: for HTTPS support via urllib3'
            'python-paramiko: for use as the SSH implementation'
            'python-pyopenssl: for HTTPS support via urllib3'
            'python-pyinotify: to watch for changes to refs')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('70955e4e249ddda6e34a4636b90f74e931e558f993b17c52570fa6144b993103')
b2sums=('a65aaa3611de6b18a3f63bd195d3831733bea726f634964c14bb817954147e45753868982fb0c3dcf57dec5a2ed8c985229d110234fd6cae8c783367a06bc20c')

build() {
  cd $_name-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $_name-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m unittest dulwich.tests.test_suite
}

package() {
  cd $_name-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
}
