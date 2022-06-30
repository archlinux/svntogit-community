# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Timothée Ravier <tim@siosm.fr>

_name=dulwich
pkgname=python-dulwich
pkgver=0.20.44
pkgrel=1
pkgdesc='Pure-Python implementation of the Git file formats and protocols'
arch=('x86_64')
url=https://www.dulwich.io
license=('GPL')
depends=('python-certifi' 'python-urllib3')
makedepends=('python-setuptools')
checkdepends=('python-gpgme' 'python-paramiko')
optdepends=('python-fastimport: for fast-import support'
            'python-gpgme: for PGP signature support'
            'python-idna: for HTTPS support via urllib3'
            'python-paramiko: for use as the SSH implementation'
            'python-pyopenssl: for HTTPS support via urllib3'
            'python-pyinotify: to watch for changes to refs')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('10e8d73763dd30c86a99a15ade8bfcf3ab8fe96532cdf497e8cb1d11832352b8')
b2sums=('ba120c682b0fd298a9f17eec524ffdd92af9024e30d0b8c52accda3ef8a1d4876b483e8aaa5f12b4beb73a6c1719ed4504c52396cd355244ab688ceab551faaf')

build() {
  cd $_name-$pkgver
  python setup.py build
}

check() {
  cd $_name-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python setup.py install --optimize=1 --skip-build
  test-env/bin/python -m unittest dulwich.tests.test_suite
}

package() {
  cd $_name-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}
