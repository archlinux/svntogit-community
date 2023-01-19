# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Timothée Ravier <tim@siosm.fr>

_name=dulwich
pkgname=python-dulwich
pkgver=0.21.2
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
sha256sums=('d865ae7fd9497d64ce345a6784ff1775b01317fba9632ef9d2dfd7978f1b0d4f')
b2sums=('8c3b42e103146c3641292eaaae29b2e53690a84fe0ba68adcaecc7ed75ce5ee3af64cffcc702b98a5bef18b6edfe888b2db0232430cf0289d1ca14dd49f3fb14')

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
