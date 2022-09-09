# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-sphinxcontrib-towncrier
pkgver=0.3.0a0
pkgrel=1
pkgdesc="An RST directive for injecting a Towncrier-generated changelog draft containing fragments for the unreleased (next) project version"
url="https://github.com/sphinx-contrib/sphinxcontrib-towncrier"
license=('BSD')
arch=('any')
depends=('python-sphinx' 'towncrier')
makedepends=('python-setuptools')
checkdepends=('python-pytest-xdist')
source=("https://github.com/sphinx-contrib/sphinxcontrib-towncrier/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('daf2292a19229b24f0f51658218bb9dbec42c4d1db4a1d370435f5e9cb1855c7af1896c2a99e5a9d1f2ffeb079e195169eeeee36c3658d5d490f3e196eb6cb33')

prepare() {
  cd sphinxcontrib-towncrier-$pkgver
  sed -i '/pytest_cov/d;/--cov/d' pytest.ini
}

build() {
  cd sphinxcontrib-towncrier-$pkgver
  python setup.py build
}

check() {
  cd sphinxcontrib-towncrier-$pkgver
  python setup.py egg_info
  PYTHONPATH="$PWD"/src pytest
}

package() {
  cd sphinxcontrib-towncrier-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
