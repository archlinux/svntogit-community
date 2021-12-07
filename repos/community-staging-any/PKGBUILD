# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-jaraco.context
pkgver=4.0.0
pkgrel=3
pkgdesc="Context managers by jaraco"
url="https://github.com/jaraco/jaraco.context"
license=('MIT')
arch=('any')
depends=('python-jaraco' 'python-yg.lockfile')
makedepends=('python-setuptools-scm' 'python-toml')
checkdepends=('python-pytest-black' 'python-pytest-checkdocs' 'python-pytest-cov'
              'python-pytest-flake8' 'python-pytest-mypy' 'python-jaraco.test'
              'python-pip')
source=("https://github.com/jaraco/jaraco.context/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('90a2010d87ac75f24c17bc054c664eeb442d9a7d4148d4f489a493aba9fdf654826f341b88ecad95943ce30aec934c5574d33dbd6cfcb67057315d7c3d5f31ff')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cd jaraco.context-$pkgver
  sed -i '/import jaraco.apt/d' jaraco/context.py
  # Ignore flake8 error introduced by the above apt workaround
  echo -e '\nper-file-ignores =\n\tjaraco/context.py: F821' >> .flake8
}

build() {
  cd jaraco.context-$pkgver
  python setup.py build
}

check() {
  cd jaraco.context-$pkgver
  python -m pytest
}

package() {
  cd jaraco.context-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1

  install -Dm644 LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
