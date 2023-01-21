# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-hatch-vcs
pkgver=0.3.0
pkgrel=1
pkgdesc="Hatch plugin for versioning with your preferred VCS"
url="https://github.com/ofek/hatch-vcs"
license=('MIT')
arch=('any')
depends=('python-hatchling' 'python-setuptools-scm')
makedepends=('python-build' 'python-installer')
checkdepends=('python-pytest' 'git')
source=("https://github.com/ofek/hatch-vcs/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
sha512sums=('ce22937aae8130a485ab154378f6c58c1720d66d277349a95ccfb58fd748deb69cd17d34ec3a12f3201f9e348e5d5b1c6b977432e614bb42d0e3065ec5f7f9c6')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd hatch-vcs-$pkgver
  python -m build -nw
}

check() {
  cd hatch-vcs-$pkgver
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  python -m installer --destdir=tmp_install dist/*.whl
  SETUPTOOLS_SCM_PRETEND_VERSION= PYTHONPATH="$PWD/tmp_install$site_packages" pytest
}

package() {
  cd hatch-vcs-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE.txt -t "$pkgdir"/usr/share/licenses/$pkgname/
}
