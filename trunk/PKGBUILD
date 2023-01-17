# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Timothée Ravier <tim@siosm.fr>

_name=dulwich
pkgname=python-dulwich
pkgver=0.21.1
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
sha256sums=('5e9d7b158638248036f5f275dcb8b040b18ca2dda329cfdb6749ef40aebdd6f1')
b2sums=('b821eb8a195496066017c0f9c9076ed25e1bfb894cead5175143a8944a16b8a82ca54d9a65d1aea23d7a039ce63343c608e2694f756b65b49e345d0ff49293f4')

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
