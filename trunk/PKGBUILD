# Maintainer: Filipe Laíns (FFY00) <lains@archlinux.org>

_pkgname=sphinx-inline-tabs
pkgname=python-$_pkgname
pkgver=2020.10.19.beta4
pkgrel=4
pkgdesc='Add inline tabbed content to your Sphinx documentation'
arch=('any')
url='https://github.com/pradyunsg/sphinx-inline-tabs'
license=('MIT')
depends=('python-sphinx')
makedepends=('python-setuptools' 'python-dephell')
source=("$pkgname-$pkgver.tar.gz::$url/archive/$pkgver.tar.gz"
        setup.py)
sha512sums=('4f2d6c373a189f2fc86b33bb7ebb13b25063b897718e5678e61f4b5d7fb1fe49fd7016c1bfd07df7d29220a7be6ebceb63193546b9cbaab6184926d7d2e0b4ff'
            '15adbcf10374f0bba9641c50dd6904871a520780229501154d9638479ee6507cf939469c725860f122a9350408e80a93405131e3e4dae352b99cf036da824271')

prepare() {
  cd $_pkgname-$pkgver

  #dephell deps convert --from pyproject.toml --to setup.py

  # Bootstrapping for Python 3.10
  cp ../setup.py .
}

build() {
  cd $_pkgname-$pkgver

  python setup.py build
}

package() {
  cd $_pkgname-$pkgver

  python setup.py install --root="$pkgdir" --optimize=1 --skip-build

  install -Dm 644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
