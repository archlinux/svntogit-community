# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=asttokens
pkgname=python-asttokens
pkgver=2.0.5
pkgrel=2
pkgdesc='Get the currently executing AST node of a frame, and other information'
arch=('any')
url=https://github.com/gristlabs/asttokens
license=('Apache')
depends=('python-six')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm'
             'python-wheel')
checkdepends=('python-astroid' 'python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('9a54c114f02c7a9480d56550932546a3f1fe71d8a02f1bc7ccd0ee3ee35cf4d5')
b2sums=('44fd821230dbec4b2e4182872bd3509becb4669c6c1d3a143a33a86cd2b8d7fd94e8cee77390834475d9290ac3723735a7d6ba3b3695758a89c46a106a56501a')

build() {
  cd "$_name-$pkgver"
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd "$_name-$pkgver"
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m pytest
}

package() {
  cd "$_name-$pkgver"
  python -m installer --destdir="$pkgdir" dist/*.whl

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$_name-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
