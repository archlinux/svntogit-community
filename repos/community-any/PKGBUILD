# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=asttokens
pkgname=python-asttokens
pkgver=2.0.8
pkgrel=1
pkgdesc='Get the currently executing AST node of a frame, and other information'
arch=('any')
url=https://github.com/gristlabs/asttokens
license=('Apache')
depends=('python-six')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm'
             'python-wheel')
#checkdepends=('python-astroid' 'python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('c61e16246ecfb2cde2958406b4c8ebc043c9e6d73aaa83c941673b35e5d3a76b')
b2sums=('ca0d3086ef5c2bdf6cacb1edc2f8849c01fcfacb39e1f1b88e6c29dd65c15debe35ffa05cfce99fc914cf67909ddcf5340ccb70e7d7e194a8b4abd531b7f725b')

build() {
  cd "$_name-$pkgver"
  python -m build --wheel --skip-dependency-check --no-isolation
}

#check() {
#  cd "$_name-$pkgver"
#  python -m venv --system-site-packages test-env
#  test-env/bin/python -m installer dist/*.whl
#  test-env/bin/python -m pytest
#}

package() {
  cd "$_name-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$_name-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
