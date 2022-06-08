# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Chih-Hsuan Yen <yan12125@archlinux.org>
# Contributor: Kyle Keen <keenerd@gmail.com>

pkgname=python-jaraco.collections
pkgver=3.5.1
pkgrel=2
pkgdesc="Models and classes to supplement the stdlib 'collections' module."
arch=('any')
url='https://github.com/jaraco/jaraco.collections'
license=('MIT')
depends=('python-jaraco.text' 'python-jaraco.classes')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
checkdepends=('python-pytest-black' 'python-pytest-checkdocs' 'python-pytest-cov'
              'python-pytest-enabler' 'python-pytest-flake8' 'python-pytest-mypy'
              'python-pip')
conflicts=('python-jaraco')
replaces=('python-jaraco')
source=("https://files.pythonhosted.org/packages/source/j/jaraco.collections/jaraco.collections-$pkgver.tar.gz")
sha512sums=('2918be537296ca81e5f78a3966a47451dc9dc2d233d997c3f01461c489b44051c497dab55496f85883ac1b91a28850a9d77ff154a3f5e074da1ed07f3259c246')

build() {
  cd jaraco.collections-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd jaraco.collections-$pkgver
  python -m pytest
}

package() {
  cd jaraco.collections-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
