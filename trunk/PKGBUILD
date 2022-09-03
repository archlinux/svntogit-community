# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=towncrier
pkgver=22.8.0
pkgrel=1
pkgdesc="Utility to produce useful, summarised news files for your project"
arch=('any')
url="https://github.com/hawkowl/towncrier"
license=('MIT')
depends=('python-click' 'python-click-default-group' 'python-incremental' 'python-jinja'
         'python-setuptools' 'python-tomli')
checkdepends=('git' 'python-twisted')
source=("https://pypi.io/packages/source/t/towncrier/towncrier-$pkgver.tar.gz")
sha512sums=('addaf9b39052cafbfebbe33497cf76c516620bfd030080fce7347bc3c1b80d728d0116f2f8a2a123979fbbaed91117514ef8fae21f3c145b7553887ea96aa031')

build() {
  cd towncrier-$pkgver
  python setup.py build
}

check() {
  cd towncrier-$pkgver
  python setup.py install --root="$PWD/tmp_install" --optimize=1
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.10/site-packages" PATH="$PWD/tmp_install/usr/bin:$PATH" trial towncrier
}

package() {
  cd towncrier-$pkgver
  python setup.py install -O1 --prefix=/usr --root="$pkgdir"

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}

# vim:set ts=2 sw=2 et:
