# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_pkgname=installer
pkgname=python-$_pkgname
pkgver=0.5.0
pkgrel=1
pkgdesc='Low-level library for installing a Python package from a wheel distribution'
arch=('any')
url='https://github.com/pradyunsg/installer'
license=('MIT')
depends=('python')
makedepends=('git' 'python-flit-core' 'python-setuptools'
             'python-sphinx' 'python-sphinx-furo' 'python-myst-parser'
             'python-sphinx-argparse')
checkdepends=('python-pytest' 'python-mock')
source=("https://files.pythonhosted.org/packages/source/${_pkgname::1}/${_pkgname}/${_pkgname}-${pkgver}.tar.gz")
sha256sums=('0cd6bdab3b358cf7e8749370b99aef9e12202751271c5ddb22126599b34dc665')
sha512sums=('7ff44c24d43080737261ad6b422b202638a414429cfc674d54f66a53e28a451dc29c73dc721bcd26bb447b80e965dc2c6a1c8bc5543eb39763776f6f4ed2bfcc')

build() {
  cd $_pkgname-$pkgver

  python setup.py build

  PYTHONPATH=src sphinx-build -b dirhtml -v docs docs/build/html
}

check() {
  cd $_pkgname-$pkgver

  PYTHONPATH=src pytest
}

package() {
  cd $_pkgname-$pkgver

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  # remove windows entrypoint scripts executables
  rm "$pkgdir"/usr/lib/python*/site-packages/installer/_scripts/*.exe

  # install documentation
  install -dm 755 "$pkgdir"/usr/share/doc/$pkgname
  cp -r -a --no-preserve=ownership docs/build/html "$pkgdir"/usr/share/doc/$pkgname
  rm -rf "$pkgdir"/usr/share/doc/$pkgname/html/.doctrees

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
