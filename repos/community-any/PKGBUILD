# Maintainer: Kyle Keen <keenerd@gmail.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: PepeSmith
# Contributor: Aron Asor <aronasorman at gmail.com>
# Contributor: Chris Brannon <chris@the-brannons.com>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgname=ipython
pkgver=8.4.0
pkgrel=1
pkgdesc="An enhanced Interactive Python shell."
arch=('any')
url="https://ipython.org"
license=('BSD')
depends=('python' 'python-traitlets' 'python-pexpect' 'sqlite'
         'python-pickleshare' 'python-prompt_toolkit'
         'python-jedi' 'python-pygments' 'python-backcall'
         'python-matplotlib-inline' 'python-stack-data')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')
# texlive-bin checkdep excluded due to test_latex_to_png_color failure
checkdepends=('python-pytest' 'python-pytest-asyncio' 'python-testpath'
              'jupyter-nbformat' 'python-ipykernel' 'python-numpy' 'python-trio'
              'python-matplotlib' 'python-curio' 'python-pandas' 'tcsh')
optdepends=('python-black: to auto format with Black'
            'yapf: to auto format with YAPF')
source=("https://files.pythonhosted.org/packages/source/${pkgname::1}/$pkgname/$pkgname-$pkgver.tar.gz"
        "IPython-icon.png::https://www.packal.org/sites/default/files/public/styles/icon_large/public/workflow-files/nkeimipynbworkflow/icon/icon.png")
sha256sums=('f2db3a10254241d9b447232cec8b424847f338d9d36f9a577a6192c332a46abd'
            '3c44a6fa1e3a8afc24754c90469404770b639cb960361988999a4cdd677699d8')
b2sums=('4a5804ad115b45568ddbc0b8fcd181ae0088690ae2d7dda8580588d1e1caa087582a279449142e0144568815270b3a9476893525c0e90320f9ec580a06126d1d'
        'd445e2bc7a037db8715ea103611720e965987e155c32e445b0ef783e519fca8a0301b16c5763fd9a5d8d169c3b0d7b4db6c0bd0f9772842258b135dcb1d6d5a2')

# confirm that an update does not break sage?

build() {
  cd $pkgname-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $pkgname-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m installer dist/*.whl
  test-env/bin/python -m pytest
}

package() {
  cd $pkgname-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl

  cd "examples/IPython Kernel"
  # FS#45120
  sed -i 's/gnome-netstatus-idle/ipython/' ipython.desktop
  install -Dm644 -t "$pkgdir/usr/share/applications" ipython.desktop
  # FS#47046
  install -Dm644 "$srcdir/IPython-icon.png" "$pkgdir/usr/share/pixmaps/ipython.png"

  # Symlink license file
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  install -d "$pkgdir"/usr/share/licenses/$pkgname
  ln -s "$site_packages"/$pkgname-$pkgver.dist-info/LICENSE \
    "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
