# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=towncrier
pkgver=22.12.0
pkgrel=3
pkgdesc="Utility to produce useful, summarised news files for your project"
arch=('any')
url="https://github.com/hawkowl/towncrier"
license=('MIT')
depends=('python-click' 'python-click-default-group' 'python-incremental' 'python-jinja'
         'python-setuptools' 'python-tomli')
checkdepends=('git' 'python-twisted')
source=("https://pypi.io/packages/source/t/towncrier/towncrier-$pkgver.tar.gz")
sha512sums=('af602610ddf77ad2d241347bd59ac915637123b65aa9da41197674ea338f8d7c86d1faa59e58e8675286c44ea266915896041bf6e16c3e920e40ca85cf04e52d')

build() {
  cd towncrier-$pkgver
  python setup.py build
}

check() {
  cd towncrier-$pkgver
  python setup.py install --root="$PWD/tmp_install" --optimize=1
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.11/site-packages" PATH="$PWD/tmp_install/usr/bin:$PATH" trial towncrier
}

package() {
  cd towncrier-$pkgver
  python setup.py install -O1 --prefix=/usr --root="$pkgdir"

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}

# vim:set ts=2 sw=2 et:
