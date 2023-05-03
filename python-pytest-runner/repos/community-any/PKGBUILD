# Maintainer: Felix Yan <felixonmars@archlinux.org>

# https://github.com/pytest-dev/pytest-runner#deprecation-notice
pkgname=python-pytest-runner
pkgver=6.0.0
_commit=a3dc9f4c6afea684ed48da998958470ea41f3c00
pkgrel=5
pkgdesc="Invoke py.test as distutils command with dependency resolution"
arch=('any')
license=('MIT')
url="https://github.com/pytest-dev/pytest-runner"
depends=('python-pytest' 'python-setuptools')
makedepends=('git' 'python-build' 'python-installer' 'python-setuptools-scm' 'python-wheel')
#checkdepends=('python-pytest-virtualenv' 'python-pytest-enabler')
source=("git+https://github.com/pytest-dev/pytest-runner.git#commit=$_commit")
sha512sums=('SKIP')

build() {
  cd pytest-runner
  python -m build --wheel --no-isolation
}

# Tries to import barbazquux2
#check() {
#  cd pytest-runner
#  PYTHONPATH="$PWD" pytest
#}

package() {
  cd pytest-runner
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
