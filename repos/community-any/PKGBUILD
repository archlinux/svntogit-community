# Maintainer: Daniel M. Capella <polyzen@archlinux.org>

_name=stack_data
pkgname=python-stack-data
pkgver=0.1.3
pkgrel=2
pkgdesc='Extract data from python stack frames and tracebacks for informative displays'
arch=('any')
url=https://github.com/alexmojaki/stack_data
license=('MIT')
depends=('python-asttokens' 'python-executing' 'python-pure-eval')
makedepends=('python-build' 'python-install' 'python-setuptools-scm'
             'python-wheel')
checkdepends=('python-littleutils' 'python-pygments' 'python-pytest'
              'python-typeguard')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('5cb2aff8164a81901160078ea2f5e39de978f08c96ac69e552a5c5345f892a81')
b2sums=('8d60f7c589f75dc8362c25ce88c3d46935768033373fd22846e81cce26609c8137ff64d346904ed38181dc27d24e14ed4c4d0217a1229881b6f7373ea359161f')

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
  ln -s "$site_packages"/$_name-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

# vim:set ts=2 sw=2 et:
