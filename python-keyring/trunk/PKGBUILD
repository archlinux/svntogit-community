# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

pkgname=python-keyring
_pkgname=keyring
pkgver=21.2.1
pkgrel=1
pkgdesc='Store and access your passwords safely'
arch=('any')
url='https://github.com/jaraco/keyring'
license=('PSF' 'MIT')
#depends=('python-entrypoints' 'python-secretstorage')
makedepends=('git' 'python-setuptools-scm' 'python-entrypoints' 'python-pip' 'python-wheel')
checkdepends=('python-pytest-flake8' 'python-pytest-runner' 'python-pytest-black' 'python-pytest-cov' 'python-keyrings-alt')
optdepends=('python-keyrings-alt: Alternative backends'
            'python-dbus: kwallet backend')
source=("git+$url#tag=v$pkgver")
sha512sums=('SKIP')

build() {
  cd $_pkgname

#  python -m compileall .
  python setup.py sdist bdist_wheel
}

check() {
  cd $_pkgname

#  python setup.py pytest
}

package() {
  cd $_pkgname

  pip install -I --no-deps --root "$pkgdir" dist/$_pkgname-$pkgver-py3-none-any.whl
  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE

  rm -rf "$pkgdir"/usr/lib/python3.8/site-packages/keyring/tests
}

# vim:set ts=2 sw=2 et:
