# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=pure_eval
pkgname=python-pure-eval
pkgver=0.2.1
pkgrel=2
pkgdesc='Safely evaluate AST nodes without side effects'
arch=('any')
url=https://github.com/alexmojaki/pure_eval
license=('MIT')
depends=('python')
makedepends=('python-build' 'python-install' 'python-setuptools-scm'
             'python-wheel')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('0f04483b16c9429532d2c0ddc96e2b3bb6b2dc37a2bfb0e986248dbfd0b78873')
b2sums=('6907cf2fc2a7118274a80dacdebeae163be57cc31086bc66f8ad9960f4624accde78149db9098bfba902774b367e2e0e9c5aac53c4e75119465d5f07cabbf17d')

build() {
  cd "$_name-$pkgver"
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd "$_name-$pkgver"
  python -m venv --system-site-packages test-env
  test-env/bin/python -m install --optimize=1 dist/*.whl
  test-env/bin/python -m pytest
}

package() {
  cd "$_name-$pkgver"
  python -m install --optimize=1 --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$_name-$pkgver.dist-info/LICENSE.txt \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE.txt
}

# vim:set ts=2 sw=2 et:
