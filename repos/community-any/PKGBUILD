# Maintainer: Kyle Keen <keenerd@gmail.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: PepeSmith
# Contributor: Aron Asor <aronasorman at gmail.com>
# Contributor: Chris Brannon <chris@the-brannons.com>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgname=ipython
pkgver=8.0.0
pkgrel=1
pkgdesc="An enhanced Interactive Python shell."
arch=('any')
url="https://ipython.org"
license=('BSD')
depends=('python' 'python-traitlets' 'python-pexpect' 'sqlite'
         'python-pickleshare' 'python-prompt_toolkit'
         'python-jedi' 'python-pygments' 'python-backcall'
         'python-matplotlib-inline' 'python-black' 'python-stack-data')
makedepends=('python-build' 'python-install' 'python-setuptools' 'python-wheel')
# texlive-bin checkdep excluded due to test_latex_to_png_color failure
checkdepends=('python-pytest' 'python-pytest-asyncio' 'python-testpath'
              'jupyter-nbformat' 'python-ipykernel' 'python-numpy' 'python-trio'
              'python-matplotlib' 'python-curio' 'python-pandas' 'tcsh')
source=("https://files.pythonhosted.org/packages/source/${pkgname::1}/$pkgname/$pkgname-$pkgver.tar.gz"
        "IPython-icon.png::https://www.packal.org/sites/default/files/public/styles/icon_large/public/workflow-files/nkeimipynbworkflow/icon/icon.png")
sha256sums=('004a0d05aeecd32adec4841b6e2586d5ca35785b1477db4d8333a39333e0ce98'
            '3c44a6fa1e3a8afc24754c90469404770b639cb960361988999a4cdd677699d8')
b2sums=('8844372c423c4b33a2a77b376c033aa00a4d44d1735cad42c4c85b05950370fcafea109025f4f02d124643656673ebf45ef27f78a93d31083b94e13d9364b32c'
        'd445e2bc7a037db8715ea103611720e965987e155c32e445b0ef783e519fca8a0301b16c5763fd9a5d8d169c3b0d7b4db6c0bd0f9772842258b135dcb1d6d5a2')

# confirm that an update does not break sage?

build() {
  cd $pkgname-$pkgver
  python -m build --wheel --skip-dependency-check --no-isolation
}

check() {
  cd $pkgname-$pkgver
  python -m venv --system-site-packages test-env
  test-env/bin/python -m install --optimize=1 dist/*.whl
  test-env/bin/python -m pytest
}

package() {
  cd $pkgname-$pkgver
  python -m install --optimize=1 --destdir="$pkgdir" dist/*.whl

  # https://github.com/FFY00/python-install/pull/6
  chmod +x "$pkgdir"/usr/bin/*

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
