# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-pytest-runner
pkgver=5.3.0
pkgrel=1
pkgdesc="Invoke py.test as distutils command with dependency resolution"
arch=('any')
license=('MIT')
url="https://github.com/pytest-dev/pytest-runner"
depends=('python-pytest' 'python-setuptools')
makedepends=('python-setuptools-scm' 'python-toml')
checkdepends=('python-pytest-black' 'python-pytest-cov' 'python-pytest-virtualenv'
              'python-pytest-flake8' 'python-pytest-enabler')
source=("https://github.com/pytest-dev/pytest-runner/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('db62e26e58664c74bc3c1fa02c36e138f8a7b4aa617afa6abb13e394e1a216cc76b3b1303c256c43e1b364299ea7e9ca640ba7e0a2b0057734a93337dbcb815e')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd pytest-runner-$pkgver
  python setup.py build
}

check() {
  cd pytest-runner-$pkgver
  python setup.py egg_info
  PYTHONPATH="$PWD" pytest
}

package() {
  cd pytest-runner-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
