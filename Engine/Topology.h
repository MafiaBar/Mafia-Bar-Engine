#pragma once
#include "Bindable.h"

namespace MafiaBar
{
	namespace Engine
	{
		namespace Graphics
		{
			class MB_ENGINE_API  Topology : public Bindable
			{
			public:
				Topology(D3D_PRIMITIVE_TOPOLOGY Topolgy);
				void Bind() override;
				/// <summary>
				///  Replaces the old Topology Type with the new one that you specify.
				/// </summary>
				void Replace(const D3D_PRIMITIVE_TOPOLOGY& TopolgyType);
			private:
				D3D_PRIMITIVE_TOPOLOGY mTopolgyType;
			};
		}
	}
}
