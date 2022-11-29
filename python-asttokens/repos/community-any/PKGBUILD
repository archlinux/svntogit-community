# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=asttokens
pkgname=python-asttokens
pkgver=2.2.0
pkgrel=1
pkgdesc='Get the currently executing AST node of a frame, and other information'
arch=('any')
url=https://github.com/gristlabs/asttokens
license=('Apache')
depends=('python-six')
makedepends=('python-build' 'python-installer' 'python-setuptools-scm'
             'python-wheel')
checkdepends=('python-astroid' 'python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('e27b1f115daebfafd4d1826fc75f9a72f0b74bd3ae4ee4d9380406d74d35e52c')
b2sums=('8d20ee94961a17d94e187c6c0fce22b4a26fed90c15bdbe44382e3d752df191ad58287b5cd4fe3e5a1cc91a4c08a6e74be81124c12aa27334f8616c9256b0657')

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
