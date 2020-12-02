# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Timothée Ravier <tim@siosm.fr>

_name=dulwich
pkgname=python-dulwich
pkgver=0.20.14
pkgrel=1
pkgdesc='Pure-Python implementation of the Git file formats and protocols'
arch=('x86_64')
url=https://www.dulwich.io
license=('GPL')
depends=('python-certifi' 'python-setuptools' 'python-urllib3')
checkdepends=('python-mock')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('21d6ee82708f7c67ce3fdcaf1f1407e524f7f4f7411a410a972faa2176baec0d')
b2sums=('be3658fd12021d2d8294fa92d99fe8bbf0a04de0f97d71f4c5683580169faa19fce2c731b240a1a61b95517e9b4371a8bcaedef7748e94512b09bcd9e6ae31ad')

build() {
  cd $_name-$pkgver
  python setup.py build
}

check() {
  cd $_name-$pkgver
  python -m unittest dulwich.tests.test_suite
}

package() {
  cd $_name-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim:set ts=2 sw=2 et:
