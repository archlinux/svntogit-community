# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=python-hatch-vcs
pkgver=0.3.0
_commit=fbfc6b93c6cd195f8e0525a48637a349f765d131
pkgrel=4
pkgdesc="Hatch plugin for versioning with your preferred VCS"
url="https://github.com/ofek/hatch-vcs"
license=('MIT')
arch=('any')
depends=('python-hatchling' 'python-setuptools-scm')
makedepends=('git' 'python-build' 'python-installer')
checkdepends=('python-pytest')
source=("git+https://github.com/ofek/hatch-vcs.git#commit=$_commit")
sha512sums=('SKIP')

prepare() {
  cd hatch-vcs
  # setuptools_scm 7.1.0: https://github.com/ofek/hatch-vcs/issues/25
  git cherry-pick -n 2bf0d32f92f6609258f85131b94d0952fc0ec149
}

build() {
  cd hatch-vcs
  python -m build -nw
}

check() {
  cd hatch-vcs
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  python -m installer --destdir=tmp_install dist/*.whl
  SETUPTOOLS_SCM_PRETEND_VERSION= PYTHONPATH="$PWD/tmp_install$site_packages" pytest
}

package() {
  cd hatch-vcs
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE.txt -t "$pkgdir"/usr/share/licenses/$pkgname/
}
