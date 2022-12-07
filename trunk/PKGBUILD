# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-hatch-vcs
pkgver=0.2.1
pkgrel=1
pkgdesc="Hatch plugin for versioning with your preferred VCS"
url="https://github.com/ofek/hatch-vcs"
license=('MIT')
arch=('any')
depends=('python-hatchling' 'python-setuptools-scm')
makedepends=('python-build' 'python-installer')
checkdepends=('python-pytest' 'git')
source=("https://github.com/ofek/hatch-vcs/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('5e18cf15ffb75a96cdcfa0d19b15aa2c6f31f7066c78e64aef0a27d64eb69512e402027b5c45fc81c65fea1033bea404fc20ae6c0c465ba4b05229079b88be45')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd hatch-vcs-$pkgver
  python -m build -nw
}

check() {
  cd hatch-vcs-$pkgver
  python -m installer --destdir=tmp_install dist/*.whl
  SETUPTOOLS_SCM_PRETEND_VERSION= PYTHONPATH="$PWD/tmp_install/usr/lib/python3.10/site-packages" pytest
}

package() {
  cd hatch-vcs-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE.txt -t "$pkgdir"/usr/share/licenses/$pkgname/
}
